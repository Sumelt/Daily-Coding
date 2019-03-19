SELECT vend_id, COUNT(*) AS num_prods
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
 
