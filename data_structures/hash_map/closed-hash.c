#include "closed-hash.h"

static int getKey(int key, int size)
{
  return key % size;
}

static pBucket allocBucket(int size)
{
  return (pBucket)calloc(size, sizeof(Bucket));
}

static void setBucket(pBucket bucket, const pMember member, Status status)
{
  bucket->member = member;
  bucket->status = status;
}

int initialize(pClosedHash hash, int size)
{
  if ((hash->table = allocBucket(size)) != NULL) {
    hash->size = size;
    for (int i = 0; i < size; i++)
      hash->table[i].status = EMPTY;
    return 0;
  }
  hash->size = 0;
  return -1;
}

int appendData(pClosedHash hash, const pMember member)
{
  if (searchBucket(hash, member) == NULL) {
    int key = getKey(member->no, hash->size);
    pBucket temp;
    for (int i = 0; i < hash->size; i++) {
      temp = &hash->table[key];
      if (temp->status != FULL) {
        setBucket(temp, member, FULL);
        return 0;
      }
      key = getKey(key + 1, hash->size);
      temp = &hash->table[key];
    }
  }
  return -1;
}

pBucket searchBucket(const pClosedHash hash, const pMember member)
{
  int key = getKey(member->no, hash->size);
  pBucket temp;
  for (int i = 0; i < hash->size; i++) {
    temp = &hash->table[key];
    if (temp->status == EMPTY) break;
    else if (temp->status == FULL && temp->member->no == member->no)
      return temp;
    key = getKey(key + 1, hash->size);
  }
  return NULL;
}

void printData(const pBucket bucket)
{
  printMember(bucket->member);
}

void printTable(const pClosedHash hash)
{
  for (int i = 0; i < hash->size; i++) {
    printf("  %3d : ", i);
    if (hash->table[i].status == FULL)
      printf("%3d\n", hash->table[i].member->no);
    else puts(hash->table[i].status == EMPTY ? "EMPTY" : "DELETED");
  }
}

void deleteData(pBucket bucket, Status status)
{
  if (bucket != NULL) {
    bucket->status = status;
    free(bucket->member);
  }
}

void deleteTable(pClosedHash hash)
{
  for (int i = 0; i < hash->size; i++) {
    deleteData(&hash->table[i], EMPTY);
  free(hash->table);
  hash->size = 0;
  }
}
