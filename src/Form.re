type state = {
  name: string,
  email: string,
  password: string,
};

type action =
  | HandleNameInput(string)
  | HandleEmailInput(string)
  | HandlePasswordInput(string);

let initialState: state = {name: "", email: "", password: ""};

let reducer = (state, action) => {
  switch (action) {
  | HandleNameInput(value) => {...state, name: value}
  | HandleEmailInput(value) => {...state, email: value}
  | HandlePasswordInput(value) => {...state, password: value}
  };
};

[@react.component]
let make = () => {
  let targetValue = event => ReactEvent.Form.target(event)##value;
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let handleSubmit = event => {
    ReactEvent.Synthetic.preventDefault(event);
    Js.log(state);
  };
  <div>
    <form onSubmit={event => handleSubmit(event)}>
      <input
        type_="text"
        value={state.name}
        onChange={event => dispatch(event->targetValue->HandleNameInput)}
      />
      <input
        type_="email"
        value={state.email}
        onChange={event => dispatch(event->targetValue->HandleEmailInput)}
      />
      <input
        type_="password"
        value={state.password}
        onChange={event => dispatch(event->targetValue->HandlePasswordInput)}
      />
      <input type_="submit" value="ok" />
    </form>
  </div>;
};