open Action;

let str = ReasonReact.string;

let valueFromEvent = e =>
  (e |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj)##value;

[@react.component]
let make = (~dispatch) => {
  let (todoText, setTodoText) = React.useState(() => "");
  <form
    className="todoInputForm"
    onSubmit={e => {
      e->ReactEvent.Form.preventDefault;
      Add(todoText)->dispatch;
    }}>
    <input value=todoText onChange={e => e->valueFromEvent->setTodoText} />
    <button type_="submit" onClick={_ => Js.log("hello")}>
      {React.string("add")}
    </button>
  </form>;
};