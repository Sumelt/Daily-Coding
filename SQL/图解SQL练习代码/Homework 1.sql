-- 1.1 
create table Addressbook
(
	regist_no integer not null,
    username varchar(128) not null,
    address varchar(256) not null,
    tel_no char(10),
    mail_address char(20),
    primary key(regist_no)
);

-- 1.2
alter table addressbook 
	add column postal_code char(8) not null;

start transaction;
	insert into addressbook values(123, 'Melt', 'foshan', '17xxx', '93xx.@outlook.com', '1024');
commit;

-- version
select *
	from addressbook;

-- 1.3
-- 	drop table addressbook;