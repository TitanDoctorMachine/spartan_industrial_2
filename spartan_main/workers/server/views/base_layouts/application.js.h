const char application_js[] PROGMEM =
R"=====(
      <script>
        function handleFormSubmit(event) {
          event.preventDefault(); 
          var formAction = this.getAttribute('action');
          var formData = new FormData(this);

          open_notification('Request Sended!');

          fetch(formAction, {
            method: 'POST',
            body: formData
          })
          .then(response => response.text()) // Expecting a text response
          .then(data => {
            console.log('Success:', data);
            try {
              eval(data);
            } catch (error) {
              console.error('Error evaluating JavaScript response:', error);
            }
          })
          .catch((error) => {
            console.error('Error:', error);
          });
        }

        document.addEventListener('DOMContentLoaded', function() {
          var forms = document.querySelectorAll('form');
          forms.forEach(function(form) {
            form.addEventListener('submit', handleFormSubmit);
          });
        });

        function open_notification(message) {
          var modal = document.getElementById('notification');
          var message_for_message_modal = document.getElementById('message_for_message_modal');
          message_for_message_modal.textContent = message
          modal.style.display = 'flex';
          /*setTimeout(function() {
            closeModal();
          }, 10000);*/
        }

        function close_notification() {
          var modal = document.getElementById('notification');
          modal.style.display = 'none';
        }

        function setCookie(name, value, days) {
          var expires = "";
          if (days) {
            var date = new Date();
            date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
            expires = "; expires=" + date.toUTCString();
          }
          document.cookie = name + "=" + value + expires;
        }

        function getCookie(name) {
          var nameEQ = name + "=";
          var cookies = document.cookie.split(';');
          for (var i = 0; i < cookies.length; i++) {
            var cookie = cookies[i];
            while (cookie.charAt(0) === ' ') {
              cookie = cookie.substring(1, cookie.length);
            }
            if (cookie.indexOf(nameEQ) === 0) {
              return cookie.substring(nameEQ.length, cookie.length);
            }
          }
          return null;
        }
      </script>

      <script>

        function call_fast_ajax(route, id_system, mode) {
          var xhr = new XMLHttpRequest();
          xhr.open("POST", route, true);
          xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
          xhr.onreadystatechange = function() {
            if (xhr.readyState == 4 && xhr.status == 200) {
              console.log(xhr.responseText);
              try {
                eval(xhr.responseText);
              } catch (error) {
                console.error('Error evaluating JavaScript response:', error);
              }
            }
          };
          var parametros = "id_system=" + encodeURIComponent(id_system) + "&mode=" + encodeURIComponent(mode);
          xhr.send(parametros);
        }

      </script>
)====="
;