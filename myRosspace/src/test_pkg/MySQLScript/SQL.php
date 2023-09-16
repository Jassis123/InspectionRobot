<?php
//$_SERVER用例参考


$db=new mysqli('127.0.0.1','ljs','123456','testsql');


if ($db) 
{
	echo "连上了。";
	// mysqli_get_server_version() ;
    mysqli_select_db( $db,'testsql');
//创建数据表
	$sql = "CREATE TABLE velctrl (
	id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
	movpos int(6) NOT NULL, 
	total int(6) NOT NULL,
	deltatime float ,
	reg_date TIMESTAMP 
	) ";
	if ($db->query($sql) === TRUE) {
    	echo "Table velctrl created successfully\n";
    	$sql="INSERT INTO velctrl (movpos,total) VALUES(0,0) ";
		if($db->query($sql)==TRUE)
		{
			echo "数据表为空，新建数据成功";
		}
	} else {
	    echo "创建数据表错误: " . $db->error."\n";
	}

	// $sql = "INSERT INTO MyGuests (position_x, position_y, position_z)
	// VALUES (10.5, 11.1, 12.2)";
	
	// $sql="select id from velctrl where movpos='' or movpos IS NULL";
	// if($db->query($sql)==TRUE)
	// {
		
	// }else {
	//     echo "错误: " . $db->error."\n";
	// }

	$sql = "update velctrl set movpos=16,total=total+1  where id=1"; 	
	if ($db->query($sql) === TRUE) {
	    echo "新记录插入成功\n";
	} else {
	    echo "Error: " . $sql . "<br>" . $db->error;
	}

	

	mysqli_close($db);
}
?>