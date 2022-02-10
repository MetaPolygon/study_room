void hanoi(int n, int from, int to)
{
  if (n > 1) hanoi(n - 1, from, 6 - from - to);
  printf("%d번째 원반을 %d에서 %d로 이동\n", n, from, to);
  if (n > 1) hanoi(n - 1, 6 - from - to, to);
}
