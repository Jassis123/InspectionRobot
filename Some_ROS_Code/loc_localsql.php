<?php

// 连主库
// $hs = 'w.rdc.sae.sina.com.cn' . ':' . '3306';
// $db = mysqli_connect($hs,'mlj1myy543','215wj14mlh03wylwzmhzl02lm02hyl4x3ywyz54h');
// $hs = '127.0.0.1' . ':' . '3306';
// $db = mysqli_connect($hs,'root','123456');

$db=new mysqli('localhost','root','123456','testsql');
// 连从库
// $db = mysql_connect(SAE_MYSQL_HOST_S.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS);

if ($db) {
	echo "连上了。";
	// mysqli_get_server_version() ;
    mysqli_select_db( $db,'testsql');
    // 使用 sql 创建数据表
 //    $dropsql="DROP TABLE MyGuests";
 //    $retval = mysqli_query($db,$dropsql);
	// if(! $retval )
	// {
	//   die('数据表删除失败: ' . mysqli_error($conn));
	// }
	// echo "数据表删除成功\n";


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

	$sqldata = "SELECT id, position_x, position_y,position_z FROM MyGuests";
	$result = $db->query($sqldata);
	 
	if ($result->num_rows > 0) {
	    // 输出数据
	    echo "\nprint:\n";
	    while($row = $result->fetch_assoc()) {
	        echo "id: " . $row["id"]. " - position_x: " . $row["position_x"]. "\tposition_y:" . $row["position_y"]."\tposition_z:" . $row["position_z"];
	        echo "\n";

	        $data = print_r(array('position_x' => $row["position_x"],'position_y' => $row["position_y"],'position_z' => $row["position_z"] ),true);
	        file_put_contents('POS.txt', $data);
	    }
	} else {

	    echo "0 结果";
	}


	    // ...
	}else{
		 die('Could not connect: ' . mysqli_error());
	}

mysqli_close($db);

?>

