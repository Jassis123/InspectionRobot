<?php

// 连主库
$hs = 'w.rdc.sae.sina.com.cn' . ':' . '3306';
$db = mysqli_connect($hs,'mlj1myy543','215wj14mlh03wylwzmhzl02lm02hyl4x3ywyz54h');

// 连从库
// $db = mysql_connect(SAE_MYSQL_HOST_S.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS);



$data=(int)$_POST['movpos'];
//$data=1;
if ($db) {
	echo "连上了。";
	// mysqli_get_server_version() ;
    mysqli_select_db( $db,'app_garbagesorting');

    $sqldata = "SELECT total FROM velctrl";
	$result = $db->query($sqldata);
    $row = $result->fetch_assoc();
    echo $row["total"];
    
    $sql = "CREATE TABLE velctrl (
	id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
	movpos int(6) NOT NULL, 
	total int(6) NOT NULL,
	deltatime float ,
	reg_date TIMESTAMP 
	) ";
	if ($db->query($sql) === TRUE) {
    	//echo "Table velctrl created successfully\n";
    	$sql="INSERT INTO velctrl (movpos,total) VALUES(0,0) ";
		if($db->query($sql)==TRUE)
		{
			;//echo "数据表为空，新建数据初始化完成\n";
		}
	} else {
	    echo "创建数据表错误: " . $db->error."\n";
	}
    
    $sql = "update velctrl set movpos=$data,total=total+1  where id=1"; 	
	if ($db->query($sql) === TRUE) {
	    ;//echo "新记录更新成功\n";
	} else {
	    echo "Error: " . $sql . "<br>" . $db->error;
	}

}
	mysqli_close($db);

?>