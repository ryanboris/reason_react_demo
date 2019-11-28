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
  let targetValue = event => event->ReactEvent.Form.target##value;
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let handleSubmit = event => {
    event->ReactEvent.Synthetic.preventDefault;
    state->Js.log;
  };
  <div>
    <form onSubmit={event => event->handleSubmit}>
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