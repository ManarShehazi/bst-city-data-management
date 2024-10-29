#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define PI 3.14
#include"BTProject.h"
#define NUMLETTERS 26


//to create a tree
BT init()
{
  return NULL;
}

//check if a tree is emtpy
int isEmpty(BT a)
{
    return (a==NULL);
}

//to print all the details of a city
void showCity(city c)
{

		printf("%s , %s , %lf , %lf , %s , %s , %s , %s , %s , %d , %d\n",c.city,c.city_ascii, c.lat, c.lng, c.country,c.iso2, c.iso3, c.admin_name, c.capital,c.population, c.id);

}

//to insert a city into a desired tree
BT InsertBST(BT a,city c)
{
    if(isEmpty(a)) //if the tree is empty create a node
    {
        BT n = (BT)malloc(sizeof(struct tree));
        n->root=c;
        n->left=NULL;
        n->right=NULL;
        return n;
    }
    else //if it is not empty
    {
        if(a->root.population < c.population) //if the root's population is less than that of the city
        {
            a->right=InsertBST(a->right,c); //insert the city at the right side
        }
        else
        {
            a->left=InsertBST(a->left,c); //insert the city at the left side
        }
        return a;
    }
}

//display the cities in the tree from smallest to largest
void DisplayInOrder(BT a)
{
    if(a==NULL) return;
    DisplayInOrder(a->left);
    printf("%s, %s, %lf, %lf, %s, %s, %s, %s, %s, %d, %d\n",a->root.city,a->root.city_ascii, a->root.lat, a->root.lng, a->root.country,a->root.iso2, a->root.iso3, a->root.admin_name, a->root.capital,a->root.population, a->root.id);
    DisplayInOrder(a->right);

}
//to display all info about a city
void displaycity (city c)
{
    printf("%s located at %lf latitude %lf longitude in %s with a population of %d \n",c.city_ascii,c.lat,c.lng,c.country,c.population);
}


//to read the excel file all the data and insert them line by line i.e as cities to the tree
BT loadCities(char *fn,BT a)
{
//BT b;
FILE *fp = fopen(fn,"r");
if(fp==NULL)
	{
	    printf("Error, file cannot be opened");
	    return NULL;
	}
    city c;
    char *p;
    char row[1024];
    // Get the content line by line
    fgets(row,1024,fp);
	while(fgets(row,1024,fp))
		{
		// get a pointer to city
		p=strtok(row,",");
		strcpy(c.city,p);

		// get a pointer to city-ascii
		p=strtok(NULL,",");
		strcpy(c.city_ascii,p);

		// get a pointer to lat
		p=strtok(NULL,",");
		c.lat=atof(p); // atof function converts string to double

		// get a pointer to lng
		p=strtok(NULL,",");
		c.lng=atof(p);

		// get a pointer to country
		p=strtok(NULL,",");
		strcpy(c.country,p);

		// get a pointer to iso2
		p=strtok(NULL,",");
		strcpy(c.iso2,p);

	    // get a pointer to iso3
		p=strtok(NULL,",");
		strcpy(c.iso3,p);

	    // get a pointer to admin name
		p=strtok(NULL,",");
		if(strcmp(p,"primary")==0||strcmp(p,"admin")==0||strcmp(p,"minor")==0)
        {
            strcpy(c.admin_name,"");

            strcpy(c.capital,p);

            p=strtok(NULL,",");
		    c.population = atoi(p);

		    p=strtok(NULL,",");
		    c.id = atoi(p);

        }
        else if(isdigit(*p)==1)
        {
           strcpy(c.admin_name,"");


           strcpy(c.capital,"");



		    c.population =atoi(p);

		    p=strtok(NULL,",");
		    c.id = atoi(p);
        }
        else{
            strcpy(c.admin_name,p);

             p=strtok(NULL,",");
            if(isdigit(*p)==1)
            {
                strcpy(c.capital,"");


                c.population = atoi(p);


                p=strtok(NULL,",");
                c.id = atoi(p);
            }
            else
            {
                strcpy(c.capital,p);

               p=strtok(NULL,",");
		       c.population = atoi(p);


		      p=strtok(NULL,",");
		      c.id = atoi(p);

            }

        }

        a=InsertBST(a,c);

}
   a= rightRotate(a);
	return a;

}


//traverse the tree from largest to smallest city
void reverseOrder(BT a, int n,int*i) {//right-root-left
    if (a== NULL) return;
        reverseOrder(a->right,n,i);
        if(*i<n) {
        displaycity(a->root);
        (*i)++;}
        reverseOrder(a->left,n,i);
    }

//to display the first 10 largest cities
void Largest10cities(BT a){
    int i=0;
   reverseOrder(a,10,&i);
}

//left - root - right traversal of the tree
void inorder(BT a,int n,int*i) {
      if (a==NULL) return;
        inorder(a->left,n,i);
        if(*i<n){
        displaycity(a->root);
        (*i)++;}
        inorder(a->right,n,i);
    }

//to display first 10 smallest cities
void Smallest10cities(BT a){
    int i=0;
    inorder(a,10,&i);
}



void Largest10InCountry(BT a ,char s[30],int n,int*i){
       if(a==NULL)return;
       Largest10InCountry(a->right,s,n,i);
        if( *i<n && strcmp(a->root.country,s)==0){
        printf("%s\n",a->root.city);
        (*i)++;
        }
        Largest10InCountry(a->left,s,n,i);
}

void LargestCountries(BT a,char s[30])
{
    int i=0;
    Largest10InCountry(a,s,10,&i);
}

//takes a country and print its cities
void printCountry(BT a ,char s[30]){
     // root left right
    if (a==NULL) return;
    if(strcmp(a->root.country,s)==0)
    {
        printf("%s\n",a->root.city); //print the city's info
    }
    printCountry(a->left,s);
    printCountry(a->right,s);

}
//to print the capital of a given country
void printCapital(BT a,char*s)
{
    if(a==NULL) return;
    if(strcmp(a->root.country,s)==0 && strcmp(a->root.capital,"primary")==0) //primary in capital field means it is the capital
    {
        printf("The capital of %s is %s\n",s,a->root.city);
    }
    printCapital(a->left,s);
    printCapital(a->right,s);
}


//take a letter and display all the cities starting with it
void firstLetter(BT a,char c,int*count)
{
    char*s= a->root.city_ascii;
    if(a==NULL) return;
    if(c==*s)
    {
        printf("%d: %s   %d\n",*count,a->root.city_ascii,a->root.id);//(U+00D1)
        (*count)++;
    }
    firstLetter(a->left,c,count);
    firstLetter(a->right,c,count);
}

void first(BT a,char c)
{
    int i=0;
    firstLetter(a,c,&i);
}

//take an admin/state and print all the cities in it
void cityofadmin (BT a,char *s, int *i)
{
    if (a==NULL) return;
     cityofadmin(a->left,s,i);
     if(strcmp(a->root.admin_name,s)==0)
     {

          if(*i==0)
          {
              printf("The state %s is in : %s \n",a->root.admin_name,a->root.country);
              (*i)++;
              printf("It's cities: \n");
          }
          printf("%s \n",a->root.city_ascii);
     }
     cityofadmin(a->right,s,i);

}


void printcityadmin(BT a,char *s)
{
    int i=0;
    cityofadmin ( a,s,&i);
}

//to calculate the distance between two cities using Haversine method
double distance(double lat1,double lng1,double lat2,double lng2)
{
    double radius = 6371; //earth's radius
    double dlat = (lat2-lat1)*(PI/180.0); //convert to radiant
    double dlng = (lng2-lng1)*(PI/180.0);
    lat1 = lat1*(PI/180.0);
    lat2 = lat2*(PI/180.0);
    double a = pow(sin(dlat/2),2)+cos(lat1)*cos(lat2)*pow(sin(dlng/2),2);
    double c = 2*atan2(sqrt(a),sqrt(1-a));
    double d = radius*c;
    return d; //return the distance
}

BT InsertBSTaccToDist(BT a,city c,double latitude,double longitude) //inserts cities to a tree according to their distances
{
    if(isEmpty(a))
    {
        BT n = (BT)malloc(sizeof(struct tree));
        n->root=c;
        n->left=NULL;
        n->right=NULL;
        return n;
    }
    else
    {
        if(distance(latitude,longitude,a->root.lat,a->root.lng)< distance(latitude,longitude,c.lat,c.lng))//if the distance from the root to the desired city is less than that with the city i am inserting
        {
            a->right=InsertBSTaccToDist(a->right,c,latitude,longitude);
        }
        else
        {
            a->left=InsertBSTaccToDist(a->left,c,latitude,longitude);
        }
        return a;
    }
}


//read data from the file and insert cities to a tree acc to theri distances wrt a certain city given its longitude and latitude
BT BuildTreeForClosest10(char *fn,BT n,double latitude,double longitude)
{
FILE *fp = fopen(fn,"r");
if(fp==NULL)
	{
	    printf("Error, file cannot be opened");
	    return NULL;
	}
    city c;
    char *p;
    char row[1024];
    // Get the content line by line
    fgets(row,1024,fp);
	while(fgets(row,1024,fp))
		{
		// get a pointer to city
		p=strtok(row,",");
		strcpy(c.city,p);

		// get a pointer to city-ascii
		p=strtok(NULL,",");
		strcpy(c.city_ascii,p);

		// get a pointer to lat
		p=strtok(NULL,",");
		c.lat=atof(p); // atof function converts string to double

		// get a pointer to lng
		p=strtok(NULL,",");
		c.lng=atof(p);

		// get a pointer to country
		p=strtok(NULL,",");
		strcpy(c.country,p);

		// get a pointer to iso2
		p=strtok(NULL,",");
		strcpy(c.iso2,p);

	    // get a pointer to iso3
		p=strtok(NULL,",");
		strcpy(c.iso3,p);

	    // get a pointer to admin name
		p=strtok(NULL,",");
		if(strcmp(p,"primary")==0||strcmp(p,"admin")==0||strcmp(p,"minor")==0)
        {
            strcpy(c.admin_name,"");

            strcpy(c.capital,p);

            p=strtok(NULL,",");
		    c.population = atoi(p);

		    p=strtok(NULL,",");
		    c.id = atoi(p);

        }
        else if(isdigit(*p)==1)
        {
           strcpy(c.admin_name,"");


           strcpy(c.capital,"");



		    c.population =atoi(p);

		    p=strtok(NULL,",");
		    c.id = atoi(p);
        }
        else{
            strcpy(c.admin_name,p);

             p=strtok(NULL,",");
            if(isdigit(*p)==1)
            {
                strcpy(c.capital,"");


                c.population = atoi(p);


                p=strtok(NULL,",");
                c.id = atoi(p);
            }
            else
            {
                strcpy(c.capital,p);

               p=strtok(NULL,",");
		       c.population = atoi(p);


		      p=strtok(NULL,",");
		      c.id = atoi(p);

            }

        }
        n=InsertBSTaccToDist(n,c,latitude,longitude);
}
   n= rightRotate(n);
	return n;

}

//given long and lat of a city display the closest 10 to it
void DisplayClosestCities(BT a,double latitude,double longitude){
 BT b = init();
 b = BuildTreeForClosest10("C:\\Users\\win10\\OneDrive\\Desktop\\worldcitiesBat.csv",b,latitude,longitude);//create a new tree
  //Smallest10cities(a);
  int i =0;
  inorder(b,10,&i);


}

void storing(BT a,FILE *fp)
{
    if(a!=NULL)
    {
        storing(a->left,fp);
        fprintf(fp,"%s,",a->root.city);
        fprintf(fp,"%s,",a->root.city_ascii);
        fprintf(fp,"%lf,",a->root.lat);
        fprintf(fp,"%lf,",a->root.lng);
        fprintf(fp,"%s,",a->root.country);
        fprintf(fp,"%s,",a->root.iso2);
        fprintf(fp,"%s,",a->root.iso3);
        fprintf(fp,"%s,",a->root.admin_name);
        fprintf(fp,"%s,",a->root.capital);
        fprintf(fp,"%d,",a->root.population);
        fprintf(fp,"%d \n",a->root.id);
        storing(a->right,fp);
    }
}


//create a file with the data printed on it
void datatofile (BT a)
{
    FILE *fp;
    fp=fopen("C:\\Users\\win10\\OneDrive\\Desktop\\fileConv.txt","w");
    storing(a,fp);
    fclose(fp);
}



//for balancing the tree
BT rightRotate(BT a){

BT x = a->left;
BT temp = x->right;

x->right = a;
a->left = temp;

return x;

}


int main()
{
    char s[30];
    char s1[30];
    char s2[30];
    char c;
    char w[30];
    double longt,lat;
    BT b=init();
    b=loadCities("C:\\Users\\win10\\OneDrive\\Desktop\\worldcitiesBat.csv",b);
    // DisplayClosestCities(b,35.6897,139.6922);

    //DisplayClosestCities(b,28.66,77.23);
     int n=0;
     printf("please enter: \n");
     printf(" 1. to print 10 largest cities \n 2. to print 10 smallest cities \n 3. to enter a country and print cities from this country  \n 4. to enter a latitude and longitude and print 10 closest cities \n 5. Give a country to check its largest 10 cities \n 6. Give a letter to check all the countries that start with this letter \n 7. Give a country to get its capital \n 8. Give an admin name to get its cities and the country it belongs to \n 9. click if you want to save data in a file \n quit to quit \n");
   while(1)
   {
    scanf("%d",&n);
    switch(n){

       case 1:
             printf("the 10 largest cities are:\n");
             Largest10cities(b);
             break;

       case 2:
             printf("the 10 smallest cities are:\n");
             Smallest10cities(b);
             break;

       case 3:
             printf("enter a country to print its cities\n");
             getchar();
             gets(s);
             printCountry(b,s);
             break;

       case 4:
             printf("enter a latitude: ");
             scanf("%lf",&lat);
             printf("enter a longitude: ");
             scanf("%lf",&longt);
             DisplayClosestCities(b,lat,longt);
             break;

       case 5:
           printf("give a country to check its largest 10 cities \n");
           getchar();
           gets(s1);
           LargestCountries(b,s1);
           break;

       case 6:
           printf("give a letter to check all the cities starting with this letter \n");
           scanf("%c",&c);
           first(b,c);
           break;

       case 7:
         printf("enter a country to get its capital \n");
         getchar();
         gets(s2);
         printCapital(b,s2);
         break;

       case 8:
        printf("enter an admin name \n");
        getchar();
        gets(w);
        printcityadmin(b,w);
        break;

       case 9:
           datatofile(b);
           printf("done \n");
           break;

      default:
            printf("quit");
            break;

   }
if(n==10)
    break;

   }
    return 0;
}
