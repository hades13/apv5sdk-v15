/**********************************************************************************
* Copyright (c) 2008-2011  Beijing Autelan Technology Co. Ltd.
* All rights reserved.
*
* filename: apStatisticsTable.c
* description:  implementation for the statistic information of AP
* 
*
* 
************************************************************************************/

/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.old-api.conf 14476 2006-04-18 17:36:51Z hardaker $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "apStatisticsTable.h"

#define TABLE_SIZE   1
#ifndef UCHAR
  typedef unsigned char UCHAR;
#endif


/* 
 * apStatisticsTable_variables_oid:
 *   this is the top level oid that we want to register under.  This
 *   is essentially a prefix, with the suffix appearing in the
 *   variable below.
 */

//oid apStatisticsTable_variables_oid[] = { 1,3,6,1,4,1,31656,2,3,2,1,7 };
oid *apStatisticsTable_variables_oid;

/* 
 * variable4 apStatisticsTable_variables:
 *   this variable defines function callbacks and type return information 
 *   for the apStatisticsTable mib section 
 */

struct variable4 apStatisticsTable_variables[] = {
/*  magic number        , variable type , ro/rw , callback fn  , L, oidsuffix */

#define APAUTHINVAILDFAILURETIMES		1
{APAUTHINVAILDFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 1 }},
#define APAUTHTIMEOUTFAILURETIMES		2
{APAUTHTIMEOUTFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 2 }},
#define APAUTHREFUSEFAILURETIMES		3
{APAUTHREFUSEFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 3 }},
#define APAUTHOTHERFAILURETIMES		4
{APAUTHOTHERFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 4 }},
#define APASSOCINVAILDFAILURETIMES		5
{APASSOCINVAILDFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 5 }},
#define APASSOCTIMEOUTFAILURETIMES		6
{APASSOCTIMEOUTFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 6 }},
#define APASSOCREFUSEFAILURETIMES		7
{APASSOCREFUSEFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 7 }},
#define APASSOCOTHERFAILURETIMES		8
{APASSOCOTHERFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 8 }},
#define APUSRREASSOCTIMES		9
{APUSRREASSOCTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 9 }},
#define APUSRREASSOCSUCCESSTIMES		10
{APUSRREASSOCSUCCESSTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 10 }},
#define APREASSOCINVAILDFAILURETIMES		11
{APREASSOCINVAILDFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 11 }},
#define APREASSOCTIMEOUTFAILURETIMES		12
{APREASSOCTIMEOUTFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 12 }},
#define APREASSOCREFUSEFAILURETIMES		13
{APREASSOCREFUSEFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 13 }},
#define APREASSOCOTHERFAILURETIMES		14
{APREASSOCOTHERFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 14 }},
#define APIDENTIFUSRTRYTIMES		15
{APIDENTIFUSRTRYTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 15 }},
#define APIDENTIFUSRSUCCESSTIMES		16
{APIDENTIFUSRSUCCESSTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 16 }},
#define APIDENTIFUSRKEYERRORTIMES		17
{APIDENTIFUSRKEYERRORTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 17 }},
#define APIDENTIFINVAILDFAILURETIMES		18
{APIDENTIFINVAILDFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 18 }},
#define APIDENTIFTIMEOUTFAILURETIMES		19
{APIDENTIFTIMEOUTFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 19 }},
#define APIDENTIFREFUSEFAILURETIMES		20
{APIDENTIFREFUSEFAILURETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 20 }},
#define APIDENTIFOTHERREASONTIMES		21
{APIDENTIFOTHERREASONTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 21 }},
#define APDEAUTHENTICATIONTIMES		22
{APDEAUTHENTICATIONTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 22 }},
#define APDEAUTHUSRLEAVETIMES		23
{APDEAUTHUSRLEAVETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 23 }},
#define APDEAUTHDEFICIENCYTIMES		24
{APDEAUTHDEFICIENCYTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 24 }},
#define APDEAUTHABNORMALTIMES		25
{APDEAUTHABNORMALTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 25 }},
#define APDEAUTHOTHERREASONTIMES		26
{APDEAUTHOTHERREASONTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 26 }},
#define APDISASSOCIATIONTOTALTIMES		27
{APDISASSOCIATIONTOTALTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 27 }},
#define APDISASSOCUSRLEAVETIMES		28
{APDISASSOCUSRLEAVETIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 28 }},
#define APDISASSOCDEFICIENCYTIMES		29
{APDISASSOCDEFICIENCYTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 29 }},
#define APDISASSOCABNORMALTIMES		30
{APDISASSOCABNORMALTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  {1, 30 }},
#define APDISASSOCOTHERREASONTIMES		31
{APDISASSOCOTHERREASONTIMES,  ASN_INTEGER,  RONLY,   var_apStatisticsTable, 2,  { 1, 31 }},
};
/*    (L = length of the oidsuffix) */


/** Initializes the apStatisticsTable module */
void
init_apStatisticsTable(void)
{

  //  'cat  /jffs/.OEM/.vendor_oid'
  FILE *fp;
  char oid_str[64]={0};
  char oid_tmp[64]={0};
  int  oid_len=0;
  int  count = 0;
  char *p = NULL;
  char *ptr=NULL;
  fp=fopen( "/jffs/.OEM/.vendor_oid","r");
  if(fp)
  {
	 	memset(oid_str,0,64);
     	fgets(oid_str,sizeof(oid_str),fp);
		oid_str[strlen(oid_str)-1] = '\0';
		fclose(fp);
  }
   else
   {
	   memset(oid_str,0,64);
   	   strcpy(oid_str, "1.3.6.1.4.1.31656");
   }
	
	memset(oid_tmp,0,64);
	strcpy(oid_tmp,oid_str);
		 
    ptr = strtok(oid_tmp, "."); 
	while(NULL != ptr)
	{
		oid_len++;
		ptr = strtok(NULL,".");
	 }
	
    oid_len = oid_len + 5;	
	apStatisticsTable_variables_oid = (oid *)malloc(sizeof(oid)*(oid_len));

    p = strtok(oid_str, ".");
    while( NULL != p)
    {
         apStatisticsTable_variables_oid[count++] = (oid)atoi(p);
         p = strtok(NULL,".");
    }
    apStatisticsTable_variables_oid[count ++] = 2;
    apStatisticsTable_variables_oid[count ++] = 3;
    apStatisticsTable_variables_oid[count ++] = 2;
    apStatisticsTable_variables_oid[count ++] = 1;
    apStatisticsTable_variables_oid[count ++] = 7;

	
    DEBUGMSGTL(("apStatisticsTable", "Initializing\n"));

    /* register ourselves with the agent to handle our mib tree */
    REGISTER_MIB_NEW("apStatisticsTable", apStatisticsTable_variables, variable4,
               apStatisticsTable_variables_oid, count); 
	

    /* place any other initialization junk you need here */
}

/*
 * var_apStatisticsTable():
 *   Handle this table separately from the scalar value case.
 *   The workings of this are basically the same as for var_apStatisticsTable above.
 */
unsigned char *
var_apStatisticsTable(struct variable *vp,
    	    oid     *name,
    	    size_t  *length,
    	    int     exact,
    	    size_t  *var_len,
    	    WriteMethod **write_method)
{
    /* variables we may use later */
    static long long_ret;
    static u_long ulong_ret;
    static unsigned char string[128];
    static oid objid[128];
    static struct counter64 c64;

    /* 
   * This assumes that the table is a 'simple' table.
   *	See the implementation documentation for the meaning of this.
   *	You will need to provide the correct value for the TABLE_SIZE parameter
   *
   * If this table does not meet the requirements for a simple table,
   *	you will need to provide the replacement code yourself.
   *	Mib2c is not smart enough to write this for you.
   *    Again, see the implementation documentation for what is required.
   */
    if (header_simple_table(vp,name,length,exact,var_len,write_method, TABLE_SIZE)
                                                == MATCH_FAILED )
    return NULL;

    /* 
   * this is where we do the value assignments for the mib results.
   */
    switch(vp->magic) {
    case APAUTHINVAILDFAILURETIMES:
	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^auth_invaild/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apAuthInvaildFailureTimes=atoi(string);
			pclose(fp);
			return ( UCHAR * )&st->apAuthInvaildFailureTimes;
	    }
	}

       
    case APAUTHTIMEOUTFAILURETIMES:
	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^auth_timeout/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apAuthTimeoutFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apAuthTimeoutFailureTimes;
	   	}
	}
     
    case APAUTHREFUSEFAILURETIMES:
	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^auth_deny/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apAuthRefuseFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apAuthRefuseFailureTimes;
	   	}
	}
    
    case APAUTHOTHERFAILURETIMES:
	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^auth_others/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apAuthOtherFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apAuthOtherFailureTimes;
	   	}
	}
    
    case APASSOCINVAILDFAILURETIMES:
	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^assoc_invaild/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apAssocInvaildFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apAssocInvaildFailureTimes;
	   	}
	}
      
    case APASSOCTIMEOUTFAILURETIMES:
   {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^assoc_timeout/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apAssocTimeoutFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apAssocTimeoutFailureTimes;
	   	}
	}
    case APASSOCREFUSEFAILURETIMES:
   {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^assoc_deny/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apAssocRefuseFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apAssocRefuseFailureTimes;
	   	}
	}
    case APASSOCOTHERFAILURETIMES:
    {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^assoc_others/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apAssocOtherFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apAssocOtherFailureTimes;
	   	}
	}
    case APUSRREASSOCTIMES:
    {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^reassoc_times/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apUsrReassocTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apUsrReassocTimes;
	   	}
	}
    case APUSRREASSOCSUCCESSTIMES:
       {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^reassoc_success/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apUsrReassocSuccessTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apUsrReassocSuccessTimes;
	   	}
	}
    case APREASSOCINVAILDFAILURETIMES:
   {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^reassoc_invaild/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocInvaildFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apReassocInvaildFailureTimes;
	   	}
	}
    case APREASSOCTIMEOUTFAILURETIMES:
     {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^reassoc_timeout/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocTimeoutFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apReassocTimeoutFailureTimes;
	   	}
	}
    case APREASSOCREFUSEFAILURETIMES:
    {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^reassoc_deny/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocRefuseFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apReassocRefuseFailureTimes;
	   	}
	}
    case APREASSOCOTHERFAILURETIMES:
    {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^reassoc_others/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocOtherFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apReassocOtherFailureTimes;
	   	}
	}
    case APIDENTIFUSRTRYTIMES:

	 {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^identify_times/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocOtherFailureTimes=atoi(string);
		   pclose(fp);
           return ( UCHAR * )&st->apIdentifUsrTryTimes;
	   	}
	}
		   
    case APIDENTIFUSRSUCCESSTIMES:

	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^identify_sucessful/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocOtherFailureTimes=atoi(string);
		   pclose(fp);
	       return ( UCHAR * )&st->apIdentifUsrSuccessTimes;
	   	}
	}
	
    case APIDENTIFUSRKEYERRORTIMES:

	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^identify_password_deny/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocOtherFailureTimes=atoi(string);
		   pclose(fp);
	       return ( UCHAR * )&st->apIdentifUsrKeyErrorTimes;
	   	}
	}
	
    case APIDENTIFINVAILDFAILURETIMES:
	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^identify_invalid/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocOtherFailureTimes=atoi(string);
		   pclose(fp);
	       return ( UCHAR * )&st->apIdentifInvaildFailureTimes;
	   	}
	}

	 
    case APIDENTIFTIMEOUTFAILURETIMES:
	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^identify_timeout/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocOtherFailureTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apIdentifTimeoutFailureTimes;
	   	}
	}

	
    case APIDENTIFREFUSEFAILURETIMES:
	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^identify_deny/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocOtherFailureTimes=atoi(string);
		   pclose(fp);
	       return ( UCHAR * )&st->apIdentifRefuseFailureTimes;
	   	}
	}


	
    case APIDENTIFOTHERREASONTIMES:
	{
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^identify_others/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apReassocOtherFailureTimes=atoi(string);
		   pclose(fp);
	       return ( UCHAR * )&st->apIdentifOtherReasonTimes;
	   	}
	}

	
    case APDEAUTHENTICATIONTIMES:
    {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^deauth_all/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apDeAuthenticationTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apDeAuthenticationTimes ;
	   	}
	}
    case APDEAUTHUSRLEAVETIMES:
   {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^deauth_user_leave/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apDeAuthUsrleaveTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apDeAuthUsrleaveTimes ;
	   	}
	}
    case APDEAUTHDEFICIENCYTIMES:
    {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^deauth_ap_ability/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apDeAuthDeficiencyTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apDeAuthDeficiencyTimes ;
	   	}
	}
    case APDEAUTHABNORMALTIMES:
     {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^deauth_unnormal/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apDeAuthAbnormalTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apDeAuthAbnormalTimes ;
	   	}
	}
    case APDEAUTHOTHERREASONTIMES:
    {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^deauth_others/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apDeAuthOtherReasonTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apDeAuthOtherReasonTimes ;
	   	}
	}
    case APDISASSOCIATIONTOTALTIMES:
    {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^disassoc_all/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apDisassociationTotalTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apDisassociationTotalTimes ;
	   	}
	}
    case APDISASSOCUSRLEAVETIMES:
   {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^disassoc_user_leave/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apDisassocUsrleaveTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apDisassocUsrleaveTimes ;
	   	}
	}
    case APDISASSOCDEFICIENCYTIMES:
    {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^disassoc_ap_ability/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apDisassocDeficiencyTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apDisassocDeficiencyTimes ;
	   	}
	}
    case APDISASSOCABNORMALTIMES:
    {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^disassoc_unnormal/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apDisassocAbnormalTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apDisassocAbnormalTimes ;
	   	}
	}
    case APDISASSOCOTHERREASONTIMES:
     {
	   FILE *fp;
	   char str_tmp_cmd[128];
	   memset( str_tmp_cmd, 0, 128 );
	   sprintf( str_tmp_cmd, "%s", "/usr/sbin/80211stats |awk '/^disassoc_others/{print $2}'");
          fp=popen(str_tmp_cmd,"r");
	    if(fp)
	   	{
		   memset (string, 0, 128);
		   fgets(string,sizeof(string),fp);
		   nSt.apDisassocOtherReasonTimes=atoi(string);
		   pclose(fp);
		   return ( UCHAR * )&st->apDisassocOtherReasonTimes ;
	   	}
	}
    default:
      ERROR_MSG("");
    }
    return NULL;
}

