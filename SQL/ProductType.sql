-- 根据商品种类进行汇总的表；
CREATE TABLE ProductType
	(product_type VARCHAR(32) NOT NULL,
	sum_sale_price INTEGER ,
	sum_purchase_price INTEGER ,
	PRIMARY KEY (product_type)
);

INSERT INTO ProductType (product_type, sum_sale_price, sum_purchase_price)
	SELECT product_type, SUM(sale_price), SUM(purchase_price)
	FROM Product
GROUP BY product_type;

-- drop table ProductType;