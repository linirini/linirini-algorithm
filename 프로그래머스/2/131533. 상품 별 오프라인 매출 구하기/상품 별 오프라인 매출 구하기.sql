SELECT A.product_code, SUM(A.price * B.sales_amount) as SALES 
FROM PRODUCT A
LEFT JOIN OFFLINE_SALE B on A.product_id = B.product_id
GROUP BY A.product_code
ORDER BY SALES DESC, A.product_code