import React, {Fragment, useEffect} from 'react';

import {useDispatch, useSelector} from 'react-redux';
import {getProductAction} from '../actions/productsActions';
import Product from './product';


const Products = () => {

	//mandar a llamar la accon principal para retrnar la accion
	const dispatch = useDispatch();

	useEffect(() => {
		//productos cuando el componente este listo 
		const chargeProducts  = () => dispatch( getProductAction() );
		chargeProducts();
	}, []); // el array vaco se usa para que useEfect se ejecute una ves por consulta 

	const loading = useSelector((state) => state.products.loading);
	const err = useSelector(state => state.products.err);
	const products = useSelector(state => state.products.products);

	return (
	<Fragment>
		{err ? <div className='font-wieght-bold alert alert-danger text-center mt-4'>Trow Err</div>
			: 
		<Fragment>
			<h2 className='text-center my-5'>List Products</h2>
			<table className='table table-striped'>
				<thead className='bg-primary table-dark'>
					<tr>
						<td scope='col'>Name</td>
						<td scope='col'>Price</td>
						<td scope='col'>Actions</td>
					</tr>
				</thead>
				<tbody>
					{products.map(product => (
						<Product key={product.id} product={product} />
					))}
				</tbody>
			</table>
			{loading ? 'loading' : null}
		</Fragment>
		}
	</Fragment>
	);
}

export default Products;