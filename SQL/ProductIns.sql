CREATE TABLE ProductIns
(	product_id CHAR(4) NOT NULL,
	product_name VARCHAR(100) NOT NULL,
	product_type VARCHAR(32) NOT NULL,
	sale_price INTEGER DEFAULT 0,
	purchase_price INTEGER ,
	regist_date DATE ,
	PRIMARY KEY (product_id)
);

INSERT INTO ProductIns VALUES 
	('0002', '打孔器', '办公用品', 500, 320, '2009-09-11'),
	('0003', '运动T恤', '衣服', 4000, 2800, NULL),
	('0004', '菜刀', '厨房用具', 3000, 2800, '2009-09-20');
    
INSERT INTO ProductIns (product_id, product_name, product_type, sale_price, purchase_price, regist_date) 
	VALUES ('0007', '擦菜板', '厨房用具', DEFAULT, 790, '2009-04-28');
    
-- INSERT INTO ProductIns (product_id, product_name, product_type, purchase_price, regist_date) 
-- 	VALUES ('0007', '擦菜板', '厨房用具', 790, '2009-04-28');

select * from productins;

-- drop table ProductIns;