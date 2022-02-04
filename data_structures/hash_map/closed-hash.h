#include "member.h"

enum eStatus
{
  EMPTY,
  FULL,
  DELETED,
};
typedef enum eStatus Status;

struct __Bucket
{
  pMember member;
  Status status;
};
typedef struct __Bucket Bucket, *pBucket;

struct __ClosedHash
{
  int size;
  pBucket table;
};
typedef struct __ClosedHash ClosedHash, *pClosedHash;

int initialize(pClosedHash hash, int size);
int appendData(pClosedHash hash, const pMember member);
pBucket searchBucket(const pClosedHash hash, const pMember member);
void printData(const pBucket bucket);
void printTable(const pClosedHash hash);
void deleteData(pBucket bucket, Status status);
void deleteTable(pClosedHash hash);
