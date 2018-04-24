program myDate;
{author: Jeremy Elkayam}
{* Using a date record, provides functions allowing the user
 * to set the date to either today's date or a date they provide,
 * compare dates to each other, view the date in string form, or
 * increment the date by one.
 *}

uses sysutils;

type
   day_range   = 1..31;
   month_range = 1..12;
   date_t      = record
		    day	  : day_range;
		    month : month_range;
		    year  : integer;
		
		
end;	  

var
   d1,d2,d3   : date_t;
   format_str : string;
   
{Initializes the record dt with the specified day, month, and year}
procedure init_date (var dt : date_t; day : day_range; month : month_range; year : integer);

begin
   {Set values of dt using corresponding parameters}
   dt.day:=day;
   dt.month:=month;
   dt.year:=year;
end;


{Initializes dt with today's date}
procedure init_date1 (var dt : date_t);

var
   month,day,year : word;

begin
   {grabs today's date and puts it into variables day,month,year}
   DeCodeDate(Date,year,month,day);
   dt.year:=year;
   dt.month:=month;
   dt.day:=day;
end;


{Returns true if date1 and date2 are equal}
function date_equal (date1 : date_t; date2 : date_t) : boolean;

begin
   {Dates are equal only if day, month, and year are all equal}
date_equal := (date1.year=date2.year) and (date1.month=date2.month) and (date1.day=date2.day);
end;


{Returns true if date1 is less than date2}
function date_less_than (date1 : date_t; date2 : date_t) : boolean;

begin
   {first, check if the year is less}
   if date1.year<date2.year then
      begin
	 date_less_than:=TRUE;
	 exit;
      end;
   if date1.year>date2.year then
      begin
	 date_less_than:=FALSE;
	 exit;
      end;
   {if same year, check if the month is less}
   if date1.month<date2.month then
      begin
	 date_less_than:=TRUE;
	 exit;
      end;
   if date1.month>date2.month then
      begin
	 date_less_than:=FALSE;
	 exit;
      end;
   {if same month, check if the day is less}
   if date1.day<date2.day then
      begin
	 date_less_than:=TRUE;
	 exit;
      end;
   if date1.day>date2.day then
      begin
	 date_less_than:=FALSE;
	 exit;
      end;
   date_less_than:=FALSE;
end;


{Returns the string corresponding to month}
function month_str (month : month_range) : string;

begin
   case (month) of
     1 : month_str:='January';
     2 : month_str:='February';
     3 : month_str:='March';
     4 : month_str:='April';
     5 : month_str:='May';
     6 : month_str:='June';
     7 : month_str:='July';
     8 : month_str:='August';
     9 : month_str:='September';
     10 : month_str:='October';
     11 : month_str:='November';
     12 : month_str:='December';
   end;
end;
{sets ret_str equal to the given date in string form}
procedure format_date (date : date_t; var ret_str : string);

begin
   ret_str:=concat(month_str(date.month),' ',IntToStr(date.day),', ',IntToStr(date.year));
end;


{Increments date by one day}
procedure next_day (var date : date_t);

{Returns true if the given year was a leap year}
function leap_year(year	: integer) : boolean;

begin
   leap_year:=true;
   if (not ((year mod 4) = 0)) or (((year mod 100) = 0) and (not (year mod 400 = 0))) then
      leap_year:=false;
end;


{Returns length of the given month in days}
function month_length(month : month_range; leap: boolean):day_range;

begin
   case (month) of
     1 : month_length:=31;
     {february's length changes depending on the year}
     2 :begin
	   month_length:=28;
	   if leap then 
	      month_length:=29;
        end;
     3 : month_length:=31;
     4 : month_length:=30;
     5 : month_length:=31;
     6 : month_length:=30;
     7 : month_length:=31;
     8 : month_length:=31;
     9 : month_length:=30;
     10 : month_length:=31;
     11 : month_length:=30;
     12 : month_length:=31;
   end;
end;



begin

   {Check if it's the last day of the month}
   if date.day+1>month_length(date.month,leap_year(date.year)) then
   begin
      
      {Check if it's the last month of the year}
      if date.month+1>12 then
      begin
	 {Increment the year and roll back to Jan 1}
	 date.year:=date.year+1;
	 date.month:=1;
	 date.day:=1;
	 exit;
      end;
      
      {Increment the month and roll back to the first of the month}
      date.month:=date.month+1;
      date.day:=1;
      exit;
      
   end;

   {if it's not the end of a month, just increment the day as normal}
   date.day:=date.day+1;
   
end;



begin

   {init dates}
   init_date1(d1);
   init_date(d2,31,12,1999);
   init_date(d3,1,1,2000);

   {testing format_date}
   format_date(d1,format_str);
   writeln('d1: ',format_str);
   format_date(d2,format_str);
   writeln('d2: ',format_str);
   format_date(d3,format_str);
   writeln('d3: ',format_str);
   writeln();

   {testing date comparison}
   writeln('d1 < d2? ',date_less_than(d1,d2) );
   writeln('d2 < d3? ',date_less_than(d2,d3) );
   writeln();

   {testing next day}
   next_day(d2);
   format_date(d2,format_str);
   writeln('next day d2: ',format_str);
   writeln('d2 = d3? ',date_equal(d2,d3));
   writeln();

   next_day(d2);
   format_date(d2,format_str);
   writeln('next day d2: ',format_str);
   writeln('d2 < d3? ',date_less_than(d2,d3));
   writeln('d2 = d3? ',date_equal(d2,d3));
   writeln('d2 > d3? ',(not date_less_than(d2,d3)) and (not date_equal(d2,d3)));
   writeln();
   
   init_date(d1,28,2,1529);
   format_date(d1,format_str);
   writeln('initialized d1 to ',format_str);
   next_day(d1);
   format_date(d1,format_str);
   writeln('next day d1: ',format_str);
   writeln();

   init_date(d1,28,2,1460);
   format_date(d1,format_str);
   writeln('initialized d1 to ',format_str);
   next_day(d1);
   format_date(d1,format_str);
   writeln('next day d1: ',format_str);
   writeln();

   init_date(d1,28,2,1700);
   format_date(d1,format_str);
   writeln('initialized d1 to ',format_str);
   next_day(d1);
   format_date(d1,format_str);
   writeln('next day d1: ',format_str);
   writeln();

   init_date(d1,28,2,1600);
   format_date(d1,format_str);
   writeln('initialized d1 to ',format_str);
   next_day(d1);
   format_date(d1,format_str);
   writeln('next day d1: ',format_str);
   writeln();

   

end.
