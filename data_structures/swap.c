//stable macro ver
#define swap(a,b) do{int t = a; a = b, b = t;}while(0)

//macro ver
#define swap(a,b) {int t = a; a = b, b = t;}

//function ver
void swap(int a, int b){
  int temp = a;
  a = b, b = temp;
}
