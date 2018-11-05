#include "stdafx.h"
#include <iostream>
#include "sqlite3.h"
#include "Database.h"
#include <string>
using namespace std;
string sq;
database::database() {

	rc = sqlite3_open("C:\\SqlLite3\\CMSDatabase.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}
}
int callback(void *data, int argc, char **argv, char **azColName)
{
	int i;
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

	}
	printf("\n");
	return 0;
}
void database::databaseclose()
{
	sqlite3_close(db);
}
void database::insertData(string runcode, Combined c)
{
	string a = ",";
	string b = "'";
	sq = "insert into finaldata values(" + b + runcode + b + a + to_string(c.samplenumber) + a + to_string(c.question) + a + to_string(c.joy) + a + to_string(c.fear) + a + to_string(c.disgust) + a + to_string(c.sadness) + a + to_string(c.anger) + a + to_string(c.surprise) + a + to_string(c.contempt) + a + to_string(c.calm) + a + to_string(c.angered) + a + to_string(c.joyful) + a + to_string(c.sorrow) + ");";
	sql = (char *)sq.c_str();
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}
	
	/*
	string a = ",";
	sq = "insert into Data values(" + to_string(c.samplenumber) + a + to_string(c.question) + a + to_string(c.joy) + a + to_string(c.fear) + a + to_string(c.disgust) + a + to_string(c.sadness) + a + to_string(c.anger) + a + to_string(c.surprise) + a + to_string(c.contempt) + a + to_string(c.calm) + a + to_string(c.angered) + a + to_string(c.joyful) + a + to_string(c.sorrow) + ");";
	sql = (char *)sq.c_str();
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}*/
}

void database::insertResult(string runcode, int s, int q, string J48decision, string NNdecision, string SVMdecision, string NBdecision)
{
	string a = ",";
	string c = "'";
	sq = "insert into result values(" + c + runcode + c + a + to_string(s) + a + to_string(q) + a + c + J48decision + c + a + c + NNdecision + c + a + c + SVMdecision + c + a + c + NBdecision + c + ");";
	sql = (char *)sq.c_str();
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}
}

void database::insertJ48Result(int s, int q, string decision)
{
	string c = "'";
	string a = ",";
	string sq = "insert into J48Result values(" + to_string(s) + a + to_string(q) + a + c + decision + c + ");";
	sql = (char *)sq.c_str();
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {

	}
}
void database::insertSVMResult(int s, int q, double result, string decision)
{
	string c = "'";
	string a = ",";
	string sq = "insert into SVMResult values(" + to_string(s) + a + to_string(q) + a + to_string(result) + a + c + decision + c + ");";
	sql = (char *)sq.c_str();
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {

	}
}
void database::insertNNResult(int s, int q, double success, double fail, string decision)
{
	string c = "'";
	string a = ",";
	string sq = "insert into NNResult values(" + to_string(s) + a + to_string(q) + a + to_string(success) + a + to_string(fail) + a + c + decision + c + ");";
	sql = (char *)sq.c_str();
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {

	}
}
void database::insertNBResult(int s, int q, double success, double fail, string decision)
{
	string c = "'";
	string a = ",";
	string sq = "insert into NBResult values(" + to_string(s) + a + to_string(q) + a + to_string(success) + a + to_string(fail) + a + c + decision + c + ");";
	sql = (char *)sq.c_str();
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {

	}
}