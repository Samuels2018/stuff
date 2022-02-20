import React from 'react';
import ListData from './listData';

function Tabla ({data}) {
	return (

		<div class="container">
  			<div class="row">
    			<div class="col-12">
      				<div class="table-responsive">
        				<table class="table">
        					 {data.map((dato,i) => (

								<ListData 

									key={i}
									dato={dato}
								/>

							))}
        				</table>
        			</div>
        		</div>
        	</div>
        </div>

	);
}

export default Tabla;