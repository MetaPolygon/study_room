//stable macro ver
#define swap(type, a, b) do{type t = a; a = b, b = t;}while(0)
#define swap(a, b) do{int t = a; a = b, b = t;}while(0)
#define swap(a, b) for(int t = a; b != t; a = b, b = t)

//macro ver
#define swap(a, b) {int t = a; a = b, b = t;}

//function ver
void swap(int a, int b){
  int temp = a;
  a = b, b = temp;
}
