  open_notification('User Logged Succesfully!');
  setCookie('session_token', '<S&= new_token />', 1, "/admin/");
  setTimeout(() => {
    window.location.href = '/admin/dashboard'
  }, 2000);
