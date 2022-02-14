import React from "react";
const faqs = [
  {
    question: "How do you make holy water?",
    answer:
      "You boil the hell out of it. Lorem ipsum dolor sit amet consectetur adipisicing elit. Quas cupiditate laboriosam fugiat.",
  },
  {
    question: "Lorem, ipsum dolor. ?",
    answer:
      "Lorem, ipsum dolor sit amet consectetur adipisicing elit. Cum esse odit tempora iusto iure fugiat architecto incidunt commodi pariatur itaque!.",
  },
  {
    question:
      "Lorem ipsum dolor sit amet consectetur adipisicing elit. Quisquam, libero.?",
    answer:
      "You boil the hell out of it. Lorem ipsum dolor sit amet consectetur adipisicing elit. Quas cupiditate laboriosam fugiat.",
  },
  {
    question:
      "Lorem ipsum dolor sit amet consectetur adipisicing elit. Officia??",
    answer:
      "You boil the hell out of it. Lorem ipsum dolor sit amet consectetur adipisicing elit. Quas cupiditate laboriosam fugiat.",
  },
  {
    question:
      "Lorem ipsum dolor sit amet consectetur adipisicing elit. Maxime, illo??",
    answer:
      "You boil the hell out of it. Lorem ipsum dolor sit amet consectetur adipisicing elit. Quas cupiditate laboriosam fugiat.",
  },
  {
    question:
      "Lorem, ipsum dolor sit amet consectetur adipisicing elit. Sed error laborum mollitia!?",
    answer:
      "Lorem ipsum dolor sit amet consectetur adipisicing elit. Nihil dolorem veritatis vel vero recusandae esse voluptatum quasi eligendi, consequatur facere aspernatur ipsam exercitationem maxime dignissimos! Iste quod natus nobis unde!.",
  },
  // More questions...
];

export default function Faqs() {
  return (
    <div className="bg-slate-800" id="faq">
      <div className="max-w-7xl mx-auto py-16 px-4 sm:px-6 lg:py-20 lg:px-8">
        <div className="lg:grid lg:grid-cols-3 lg:gap-8">
          <div>
            <h2 className="block bg-gradient-to-r from-green-400 to-yellow-300 bg-clip-text text-transparent text-5xl font-bold tracking-wide uppercase text-center">
              Frequently <span className="text-yellow-300">asked</span>{" "}
              questions
            </h2>
            <p className="mt-4 text-lg text-gray-300">
              Can’t find the answer you’re looking for? Reach out to our{" "}
              <a
                href="/"
                className="font-medium text-green-400 hover:text-green-500"
              >
                customer support
              </a>{" "}
              team.
            </p>
          </div>
          <div className="mt-12 lg:mt-0 lg:col-span-2">
            <dl className="space-y-12">
              {faqs.map((faq) => (
                <div key={faq.question}>
                  <dt className="text-lg leading-6 font-medium text-green-500">
                    {faq.question}
                  </dt>
                  <dd className="mt-2 text-base text-slate-400">
                    {faq.answer}
                  </dd>
                </div>
              ))}
            </dl>
          </div>
        </div>
      </div>
    </div>
  );
}
