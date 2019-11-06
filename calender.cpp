#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int getFirstDay(int year,int month);
string getMonthEn(int month); 
int getDaysCount(int year,int month);
int getDayCode(int year);
void calender(int year, int month);
int main() {
  int year, month;  
  char again = 'Y';

  while (again == 'Y')
  {
    cout << "1980년 부터 2030년까지 중의 년월을 입력하세요. (예: 2003 5) \n"; 
    cin >> year >> month ; 
    if (year < 1980 || year > 2030) {
      break;
    }
    
    cout << "입력하신 달은 " << year << "년 " << month << "월입니다.\n";
    cout << "\t\t< " << year << " " << getMonthEn(month) << " >\t\t\n";
    cout << "====================================================\n";
    cout << "Sun\t" << "Mon\t" << "Tues\t" << "Wed\t" << "Thu\t" << "Fri\t" << "Sat\n";
    cout << "----------------------------------------------------\n";
    
    calender(year, month);
    
    cout << "\n----------------------------------------------------\n";
    cout << "====================================================\n";

    cout << "다시 입력하겠습니까(Y/N) : ";
    cin >> again;
  }

  cout << "\n프로그램을 종료합니다.";

}

int getFirstDay(int year,int month)
{
  int fday=getDayCode(year);
  int num_days=0;
  int dCode=getDayCode(year);
  switch(month)
  {
    case 12: num_days+=30;
    case 11: num_days+=31;
    case 10: num_days+=30;
    case 9: num_days+=31;
    case 8: num_days+=31;
    case 7: num_days+=30;
    case 6: num_days+=31;
    case 5: num_days+=30;
    case 4: num_days+=31;
    case 3: num_days+=28;
    case 2: num_days+=31;
  }

  if (month==1) return(fday); else if(((year%4==0) || (year%400==0)) && month>2) return (num_days+1+dCode)%7 ; // 윤년

  else return (num_days+dCode)%7;
}

int getDaysCount(int year,int month)
{
  int num_days;
  if(month==1||month==3||month==5||month==7|| month==8|| month==10|| month==12)
  {
    num_days=31;
  }
  else if(month==2)
  {
  ; if((year%4==0) || (year%400==0)) num_days=29;else num_days=28;
  }
  else num_days=30;
  return num_days;
}


int getDayCode(int year)
{
  int fday;
  fday=(((year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400)+1)%7;
  return fday;
}


string getMonthEn(int month)
{
  string months[12]={"January","February","March","April","May","June","Junly","August","September","October","November","December"};

  return months[month-1];
}

void calender(int year, int month)
{
  int fday_month = getFirstDay(year, month);

  int num_days, i;
    if(month==1||month==3||month==5||month==7|| month==8|| month==10|| month==12)
    {
      num_days=31;
    }
    else if(month==2)
    {
    ; if((year%4==0) || (year%400==0)) num_days=29;else num_days=28;
    }
    else num_days=30;
    
    for (i=1; i<=fday_month; i++) cout<<"\t";

    int num = getDaysCount(year, month);
    int d = 1;
    int con=0;
    while(d<=num)
    {
      cout<<d<<"\t";
      if (fday_month>0) 
      {
        if (d==7-fday_month) 
        {
          cout<<"\n----------------------------------------------------\n";con=d;
        }
        else if (d%(con+7)==0) 
        {
          cout<<"\n----------------------------------------------------\n";con=d;
        }
      }
      else if(d%7==0) cout<<"\n----------------------------------------------------\n";
      d++;
    }
}