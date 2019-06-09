/*SELECT vend_id, COUNT(*) AS num_prods
  FROM products
  GROUP BY vend_id WITH ROLLUP;
  
select Person.FirstName, Person.LastName, Address.City, Address.State
from Person
left outer join Address
on Person.PersonId = Address.PersonId;

SELECT customers.cust_id, orders.order_num
FROM customers RIGHT OUTER JOIN orders
 ON orders.cust_id = customers.cust_id;
 
SELECT customers.cust_id, orders.order_num
FROM customers LEFT OUTER JOIN orders
 on customers.cust_id = orders.cust_id;
 */
select * from customers;
/*
DELIMITER //
create procedure city( in country char( 30 ), out str char( 30 ) ) comment '这是一个测试'
begin
    declare thecountry cursor 
    for
		select cust_city 
			from customers 
		where cust_country = country;
	open thecountry;
	FETCH thecountry into str;
    FETCH thecountry into str;
    -- close thecountry; 
end //
DELIMITER ;
call city( "USA", @str );

select @str;

-- show procedure status;

drop procedure city;
*/
/*
delimiter //
create trigger newInsert before insert on customers
	for each row 
		begin
			set new.cust_id = new.cust_id + 1;
            select new.cust_id into @ee;
        end//
delimiter ;

insert into customers
	values( '100014', 'Coyote Inc.', '200 Maple Lane', 'Detroit', 'MI', '44444', 'USA', 'Y Lee', 'ylee@coyote.com' );
 select @ee;
 

 
 create table temp
 (
	id int
 );
 
 create trigger del before delete on customers
	for each row insert into temp values( old.cust_id );
    
delete from customers where cust_id = 100014;
select * from temp;

drop table temp;
 */

/*
create trigger upd before update on customers
	for each row select old.cust_id into @ee;

update customers set cust_id = 200011 where cust_id = 100013;
select @ee;
*/

-- drop trigger newInsert;
set autocommit = 1;
insert into customers
	values( '100012', 'Coyote Inc.', '200 Maple Lane', 'Detroit', 'MI', '44444', 'USA', 'Y Lee', 'ylee@coyote.com' );


start transaction;
SAVEPOINT point1;
delete from customers where cust_id = 100011;
select * from customers;
rollback to point1;
select * from customers;

SHOW CHARACTER SET;
SHOW COLLATION;


USE mysql;
SELECT user FROM user;

SHOW GRANTS FOR melt;

create user melt IDENTIFIED BY 'best';

grant select on customers.* to melt;


desc customers;

select version();






 
