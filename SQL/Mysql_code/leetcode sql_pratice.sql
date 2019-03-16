select Customers.Name as 'Customers'
from Customers 
left outer join Orders 
on Orders.CustomerId = Customers.id
where Orders.CustomerId is null;

# 196
delete p1 from person p1, person p2
where p1.email = p2.email and p1.id > p2.id;

delete 
from Person 
where Id not in
(
	select p.min
	from
    (
        select min(Id) as min 
        from Person 
        group by Email
    ) as p
)