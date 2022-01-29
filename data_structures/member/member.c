#include "member.h"

static pMember allocMember()
{
  return (pMember)calloc(1, sizeof(Member));
}

static void __scanMember(pMember member, int flag)
{
  if (flag == NO) { printf("  no  : "); scanf("%d", &member->no); }
}

pMember scanMember(int flag)
{
  pMember temp = allocMember();
  if (temp == NULL) {
    puts(" [allocMember() return 'NULL']");
  } else {
    puts(" [input Member info]");
    if (flag == ALL) {
      for (int i = ALL + 1; i <= NO; i++)
        __scanMember(temp, i);
    } else __scanMember(temp, flag);
  }
  return temp;
}

void printMember(const pMember member)
{
  printf("\n  --(member)--\n"
           "  |  no : %d  |\n"
           "  ------------\n", member->no);
}

int cmpMember(const pMember m1, const pMember m2, int flag)
{
  if (flag == NO) return m1->no > m2->no ? 1 : 
                       (m1->no < m2->no ? -1 : 0);
}
