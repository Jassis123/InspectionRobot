<?php

// 连主库
$hs = 'w.rdc.sae.sina.com.cn' . ':' . '3306';
$db = mysqli_connect($hs,'mlj1myy543','215wj14mlh03wylwzmhzl02lm02hyl4x3ywyz54h');

// 连从库
// $db = mysql_connect(SAE_MYSQL_HOST_S.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS);

//$data=(int)$_POST['movpos']; //这个接收Unity传过来的数据
$data=1; //暂时随便给个值
if ($db) {
	echo "连上了。";
	// mysqli_get_server_version() ;
	//选择数据库
    mysqli_select_db( $db,'app_garbagesorting');
    
    //$sql里的是SQL语言 创建一个数据表
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
			echo "数据表为空，新建数据初始化完成\n";
		}
	} else {
	    echo "创建数据表错误: " . $db->error."\n";
	}
    
	//更新数据表数据
    $sql = "update velctrl set movpos=$data,total=total+1  where id=1"; 	
	if ($db->query($sql) === TRUE) {
	    echo "新记录更新成功\n";
	} else {
	    echo "Error: " . $sql . "<br>" . $db->error;
	}
	echo "total:".$_POST['total'];
    
    //$sql = "INSERT INTO CarMov (position_x, position_y, position_z)
	 // VALUES ($data, 11.1, 12.3)";
	 
	 //if ($db->query($sql) === TRUE) {
	  //    echo "新记录插入成功";
	  //} else {
	  //    echo "Error: " . $sql . "<br>" . $db->error;
	 // }
    
    //echo "recevie_data:";
	//echo $_POST['position_x'];
}
	mysqli_close($db);

?>