SELECT vend_id, COUNT(*) AS num_prods
  FROM products
  GROUP BY vend_id WITH ROLLUP;
  
select Person.FirstName, Person.LastName, Address.City, Address.State
from Person
left outer join Address
on Person.PersonId = Address.PersonId;