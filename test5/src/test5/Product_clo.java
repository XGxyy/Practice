package test5;   
 
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
 
public class Product_clo {     //获取商品表中的全部信息和购物车表中商品id
	ArrayList<Integer> list = new ArrayList<Integer>();
	// 获得所有商品的全部信息
	public ArrayList<product> getAllProduct() {
		Connection conn = null;
		PreparedStatement stmt = null;
		ResultSet rs = null;
		ArrayList<product> list = new ArrayList<product>();// 把商品信息放列表里
		try {
			conn = DataBaseConnection.getConnection();
			String sql = "select * from product;";
			stmt = conn.prepareStatement(sql);
			rs = stmt.executeQuery();
			while (rs.next()) {
				product product = new product();
				product.setId(rs.getInt("product_id"));
				product.setName(rs.getString("product_name"));
				product.setMsg(rs.getString("product_msg"));
				product.setPrice(rs.getInt("product_price"));
				product.setType(rs.getString("product_type"));
				product.setQuantity(rs.getInt("product_quantity"));
				product.setPicture(rs.getString("product_picture"));
				list.add(product);// 把一个商品的所有信息加入列表
			}
			return list;
		} catch (Exception ex) {
			ex.printStackTrace();
			return null;
		} finally {
			// 释放数据集对象
			if (rs != null) {
				try {
					rs.close();
					rs = null;
				} catch (Exception ex) {
					// TODO: handle exception
					ex.printStackTrace();
				}
			}
			// 释放语句对象
			if (stmt != null) {
				try {
					stmt.close();
					stmt = null;
				} catch (Exception ex) {
					// TODO: handle exception
					ex.printStackTrace();
				}
			}
		}
	}
	// 获取购物车商品的id
	public ArrayList<Integer> getCartId() {
		Connection conn = null;
		PreparedStatement stmt = null;
		ResultSet rs = null;
 
		try {
			conn = DataBaseConnection.getConnection();
			String sql = "select product_id from shopcart;";// SQL语句
			stmt = conn.prepareStatement(sql);
			rs = stmt.executeQuery();
			while (rs.next()) {
				list.add(rs.getInt(1));// 把一个商品的所有信息加入列表
			}
			return list;
		} catch (Exception ex) {
			ex.printStackTrace();
			return null;
		} finally {
			// 释放数据集对象
			if (rs != null) {
				try {
					rs.close();
					rs = null;
				} catch (Exception ex) {
					// TODO: handle exception
					ex.printStackTrace();
				}
			}
			// 释放语句对象
			if (stmt != null) {
				try {
					stmt.close();
					stmt = null;
				} catch (Exception ex) {
					// TODO: handle exception
					ex.printStackTrace();
				}
			}
		}
 
	}
	private PreparedStatement setInt(int i, int j) {
		// TODO Auto-generated method stub
		return null;
	}
 
	private PreparedStatement setString(int i, String name) {
		// TODO Auto-generated method stub
		return null;
	}
}
