typedef struct city{
 char city[30];
 char city_ascii[30];
 double lat;
 double lng;
 char country[30];
 char iso2[4];
 char iso3[4];
 char admin_name[20];
 char capital[40];
 int population;
 int id;

}city;


typedef struct tree{

 city root;
 struct tree*right;
 struct tree*left;

}*BT;




extern BT init();
extern int isEmpty(BT a);
extern BT InsertBST(BT a, city c);
extern void showCity(city c);
extern void DisplayInOrder(BT a);
extern BT loadCities(char *fn,BT a);
extern void reverseOrder(BT a,int n,int *i);
extern void Largest10cities(BT a);
extern void inorder(BT a,int n,int*i);
extern void Smallest10cities(BT a);
extern void printCountry(BT a ,char *s);
extern void displaycity (city c);
extern void printClosest10(BT a,double longitude,double latitude);
extern void firstLetter(BT a,char c,int*count);
extern void closestDistance(BT a,double longitude,double latitude,int n,int*i,double closest);
extern void cityofadmin (BT a,char *s, int *i);
extern void printcityadmin(BT a,char *s);
extern BT BuildTreeForClosest10(char *fn,BT n,double latitude,double longitude);
extern double distance(double lat1,double lng1,double lat2,double lng2);
extern BT InsertBSTaccToDist(BT a,city c,double latitude,double longitude);
extern BT rightRotate(BT a);
extern void datatofile (BT a);
extern void storing(BT a,FILE *fp);
