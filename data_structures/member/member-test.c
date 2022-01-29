#include "member.h"

int main()
{
  pMember member = scanMember(ALL);
  printMember(member);
  printf("\n  cmp : %d", cmpMember(member, &(Member){1}, 1));
}
