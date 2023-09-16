<?php
//$_SERVER用例参考
//edit by www.jbxue.com
echo "aa:";

// foreach ($_SERVER as $var => $value) {
// 	# code...
// 	echo "$var => $value\n";
// }

// echo $__SERVER['PATH'];

foreach ($_POST as $var => $value) {
	# code...
	echo "$var => $value\n";
}

//创建数据表
	$sql = "CREATE TABLE MyGuests (
	id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
	position_x float(6) NOT NULL, 
	position_y float(6) NOT NULL,
	position_z float(6) NOT NULL,
	reg_date TIMESTAMP
	)";
	if ($db->query($sql) === TRUE) {
    echo "Table MyGuests created successfully";
	} else {
	    echo "创建数据表错误: " . $db->error;
	}

	$sql = "INSERT INTO MyGuests (position_x, position_y, position_z)
	VALUES (10.5, 11.1, 12.2)";
	 
	if ($db->query($sql) === TRUE) {
	    echo "新记录插入成功";
	} else {
	    echo "Error: " . $sql . "<br>" . $db->error;
	}


?>