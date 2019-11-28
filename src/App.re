type state = {count: int};

type action =
  | Increment
  | Decrement;

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Increment => {count: state.count + 1}
        | Decrement => {count: state.count - 1}
        },
      {count: 0},
    );
  <div>
    <button onClick={_event => dispatch(Increment)}>
      {React.string("inc")}
    </button>
    <button onClick={_event => dispatch(Decrement)}>
      {React.string("dec")}
    </button>
    <div> {React.string(string_of_int(state.count))} </div>
  </div>;
};