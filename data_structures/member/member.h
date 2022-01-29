#include <stdio.h>
#include <stdlib.h>

struct __Member {
  int no;
};
typedef struct __Member Member, *pMember;

enum __eMemberInfo
{
  ALL,
  NO,
};

pMember scanMember(int flag);
void printMember(const pMember member);
int cmpMember(const pMember m1, const pMember m2, int flag);
