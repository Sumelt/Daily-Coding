-- DDL ：创建表
CREATE TABLE SampleStr
(
	str1 VARCHAR(40),
	str2 VARCHAR(40),
	str3 VARCHAR(40)
);

INSERT INTO SampleStr (str1, str2, str3) VALUES ('opx' ,
'rt',NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('abc' ,
'def' ,NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('山田' ,
'太郎' ,'是我');
INSERT INTO SampleStr (str1, str2, str3) VALUES ('aaa' ,
NULL ,NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES (NULL ,
'xyz',NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('@!#$%' ,
NULL ,NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('ABC' ,
NULL ,NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('aBC' ,
NULL ,NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('abc太郎' ,
'abc' ,'ABC');
INSERT INTO SampleStr (str1, str2, str3) VALUES ('abcdefabc' ,
'abc' ,'ABC');
INSERT INTO SampleStr (str1, str2, str3) VALUES ('micmic' ,
'i' ,'I');

SELECT str1, str2,
	concat(str1, str2) AS str_concat
FROM SampleStr;

SELECT str1, str2, str3,
	CONCAT(str1, str2, str3) AS str_concat
FROM SampleStr;

SELECT str1,
	LENGTH(str1) AS len_str
FROM SampleStr;

SELECT str1,
	LOWER(str1) AS low_str
    FROM SampleStr
WHERE str1 IN ('ABC', 'aBC', 'abc', '山田');

SELECT str1,
	upper(str1) AS low_str
    FROM SampleStr
WHERE str1 IN ('ABC', 'aBC', 'abc', '山田');

SELECT str1, str2, str3,
	REPLACE(str1, str2, str3) AS rep_str
FROM SampleStr;

SELECT str1,
	SUBSTRING(str1 FROM 3 FOR 2) AS sub_str
FROM SampleStr;

SELECT str1,
	UPPER(str1) AS up_str
FROM SampleStr
WHERE str1 IN ('ABC', 'aBC', 'abc', '山田');

SELECT CURRENT_DATE;

SELECT CURRENT_TIME;

SELECT CURRENT_TIMESTAMP;

SELECT CURRENT_TIMESTAMP,
	EXTRACT(YEAR FROM CURRENT_TIMESTAMP) AS year,
	EXTRACT(MONTH FROM CURRENT_TIMESTAMP) AS month,
	EXTRACT(DAY FROM CURRENT_TIMESTAMP) AS day,
	EXTRACT(HOUR FROM CURRENT_TIMESTAMP) AS hour,
	EXTRACT(MINUTE FROM CURRENT_TIMESTAMP) AS minute,
	EXTRACT(SECOND FROM CURRENT_TIMESTAMP) AS second;
    
SELECT CAST('0001' AS SIGNED INTEGER) AS int_col;

SELECT CAST('2009-12-14' AS DATE) AS date_col
	FROM SYSIBM.SYSDUMMY1;
    
SELECT COALESCE(str2, 'NULL')
FROM SampleStr;

SELECT CAST('0001' AS SIGNED integer) AS int_col; 