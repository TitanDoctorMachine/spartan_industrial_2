const char application_css[] PROGMEM = 
R"=====(
	<style>

		img {
				max-width: 100%;
				max-height: 100%;
				filter: invert(1);
		}

		body {
				margin: 0;
				font-family: Arial, sans-serif;
				background-color:#080808;
				color: #ffffff;
		}

		.main-content {
				margin-right: 40px; /* Ajuste para a largura do painel lateral */
				margin-left: 300px; /* Ajuste para a largura do painel lateral */
				padding: 10px;
				width: 70%;
		}

		.sidebar {
				position: fixed;
				padding-right: 10px;
				padding-top: 10px;
				height: 100%;
				background-color: #000000; /* Cor do painel lateral (preto) */
				padding-top: 20px;
				box-sizing: border-box;
				left: 0;
		}

		/*children elements*/

		.center {
				margin: 0;
				display: flex;
				align-items: center;
				justify-content: center;
		}

		.mini-card {
			letter-spacing: .025em;
			vertical-align: middle;
			border: 1px solid transparent;
			border-radius: 0.25rem;
			border-color: rgb(12, 13, 14);
			border-width: 2px;
			border-bottom-width: 10px;
			text-decoration: none;
			color: #ffffff;
			display: inline-block;
			padding: 0.625rem 1.25rem;
		}

		.nav-item {
			text-decoration: none;
			margin-top: 6px;
			width: 250px;
			font-weight: 600;
			line-height: 1.5;
			cursor: pointer;
			text-align: center;
		}

		
		.sub-card {
			margin: 5px;
			border-color: rgb(255, 255, 255)!important;
		}

		.button {
			letter-spacing: .025em;
			font-size: .875rem;
			font-weight: 600;
			line-height: 1.5;
			display: inline-block;
			padding: 0.625rem 1.25rem;
			cursor: pointer;
			text-align: center;
			vertical-align: middle;
			border: 1px solid transparent;
			border-radius: 0.25rem;
			color: #fff;
			border-color: #2a2c2e;
			background-color: #2a2c2e;
			box-shadow: 0 4px 6px rgba(50,50,93,0.11), 0 1px 3px rgba(0,0,0,0.08);
		}

		.notify_modal {
      display: none; /* Inicia oculta */
      position: fixed;
      top: 0;
      left: 0;
      width: 100%;
      height: 100%;
      background-color: rgba(0, 0, 0, 0.5); /* Fundo escuro para destacar a modal */
      align-items: center;
      justify-content: center;
    }

    .notify_modal-content {
      padding: 20px;
      border-radius: 5px;
      animation: slideIn 0.5s ease-out;
      background-color: #000000;
    }

    @keyframes slideIn {
      from {
        transform: translateY(-100%);
      }
      to {
        transform: translateY(0);
      }
    }
	</style>
)====="
;