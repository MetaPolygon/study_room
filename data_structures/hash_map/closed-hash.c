#include "closed-hash.h"

static int getKey(int key, int size)
{
  return key % size;
}

static int reGetKey(int key, int size)
{
  return (key + 1) % size;
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

pBucket searchBucket(const pClosedHash hash, const pMember member)
{
  int key = getKey(member->no, hash->size);
  pBucket temp = &hash->table[key];
  for (int i = 0; temp->status != EMPTY && i < hash->size; i++) {
    if (temp->status == FULL && temp->member->no == member->no)
      return temp;
    key = reGetKey(key, hash->size);
    temp = &hash->table[key];
  }
  return NULL;
}

int appendData(pClosedHash hash, const pMember member)
{
  int key = getKey(member->no, hash->size);
  pBucket temp = &hash->table[key];
  if (searchBucket(hash, member) == 0)
    return -1;
  for (int i = 0; i < hash->size; i++) {
    if (temp->status == EMPTY || temp->status == DELETE) {
      setBucket(temp, member, FULL);
      return 0;
    }
    key = reGetKey(key, hash->size);
    temp = &hash->table[key];
  }
  return (int)FULL;
}

void printData(const pBucket bucket)
{
  
}

void printTable(const pClosedHash hash)
{
  
}

int deleteData(pClosedHash hash, const pMember member)
{
  
}

void deleteTable(pClosedHash hash)
{
  
}
