open Todo;
open Action;

type state = {todos: list(todo)};

let todoId = ref(0);
let newTodo = text => {
  todoId := todoId^ + 1;
  {id: todoId^, completed: false, text};
};

let toggle = (id, todos) =>
  List.map(t => t.id === id ? {...t, completed: !t.completed} : t, todos);

let delete = (id, todos) => List.filter(t => t.id !== id, todos);

// reducer関数をComponent内、あるいはuseReducer内で定義すると、毎回新しい関数が作成されて、
// 実行中に更新されたりするとreducerを2回実行されたりするので注意
let reducer = (state: state, action: action) => {
  Js.log(state.todos);
  switch (action) {
  | Add(text) => {todos: [newTodo(text), ...state.todos]}
  | Toggle(id) => {todos: toggle(id, state.todos)}
  | Delete(id) => {todos: delete(id, state.todos)}
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, {todos: []});
  <main>
    <h1 className="title"> {React.string("ReasonReact TodoApp")} </h1>
    <TodoInput dispatch />
    {List.map(todo => <TodoItem todo dispatch />, state.todos)
     ->List.rev
     ->Array.of_list
     ->React.array}
  </main>;
};