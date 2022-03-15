import React from 'react';
import {Link} from 'react-router-dom';
import {useDispatch, useSelector} from 'react-redux';
import {detleteProductAction} from '../actions/productsActions';
//tengo que instalar sweetalert2
import Swall from 'sweetalert2';

const Product = ({product}) => {

	const dispatch = useDispatch();
	const confirmDeleteProduct = id => {
		console.log(id);

		Swall.fire({
			title: 'Are you Sure?',
			text: "You Won't be able to revert this!",
			type: 'Warning',
			showCancelButton: true,
			confirmButtonColor: '#3085d6',
			cancelButtonColor: '#d33',
			confirmButtonText: 'Tes, Delete it!',
			cancelButtonText: 'Cancel'
		}).then((result) => {
			if(result.value){
				Swall.fire(
					'deleted!',
					'Your file has been deleted.',
					'Success'
				)
				dispatch(detleteProductAction(id));
			}
		})
	}

	return (
		<tr>
			<td>{product.name}</td>
			<td><span className='font-weight-bold'>$ {product.price}</span></td>
			<td className='acciones'>
				<Link to={`products/edit/${product.id}`} 
				className='btn btn-primary mr-2'>Edit</Link>

				<button className='btn btn-danger' onClick={() => confirmDeleteProduct(product.id) }>Delete</button>
			</td>
		</tr>
	);
}

export default Product;