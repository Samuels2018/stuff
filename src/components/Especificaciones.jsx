import React from "react";
const features = [
  { name: "Mint Day", description: "11/03/2022" },
  {
    name: "Total number of Tokens",
    description: "10.000",
  },
  { name: "Token withheld from sale", description: "100" },
  { name: "Price per token", description: "0.22 ETH + GAS" },
  { name: "Token Type", description: "ERC-721" },
  {
    name: "Blockchain",
    description: "Ethereum.",
  },
  {
    name: "Royalty Fees",
    description: "8%.",
  },
  {
    name: "Reveal Type",
    description: "31/03/2022.",
  },
  {
    name: "Maximum number of traits",
    description: "6",
  },
  {
    name: "Smart contract",
    description: "0x54as68d486a41231dasd45454d84a",
  },
];

export default function Especificaciones() {
  return (
    <div className="bg-slate-800" id="information">
      <div className="max-w-2xl mx-auto py-24 px-4 grid items-center grid-cols-1 gap-y-16 gap-x-8 sm:px-6 sm:py-32 lg:max-w-7xl lg:px-8 lg:grid-cols-2">
        <div>
          <h2 className="block bg-gradient-to-r from-green-400 to-yellow-300 bg-clip-text text-transparent text-5xl font-bold tracking-wide uppercase text-center">
            Información Importante
          </h2>
          <p className="mt-4 text-slate-100/75">
            Lorem, ipsum dolor sit amet consectetur adipisicing elit. Sunt
            distinctio quia eveniet, laudantium in enim voluptate suscipit
            voluptatem aliquid iure.
          </p>

          <dl className="mt-16 grid grid-cols-1 gap-x-6 gap-y-4 sm:grid-cols-2 sm:gap-y-4 lg:gap-x-8">
            {features.map((feature) => (
              <div key={feature.name} className="border-t border-gray-200 pt-4">
                <dt className="font-medium text-green-400">{feature.name}</dt>
                <dd className="mt-2 text-sm text-slate-200">
                  {feature.description}
                </dd>
              </div>
            ))}
          </dl>
        </div>
        <div className="grid grid-cols-2 grid-rows-2 gap-4 sm:gap-6 lg:gap-8">
          <img
            src="https://images.unsplash.com/photo-1621632361333-4649f0b59adc?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=2360&q=80"
            alt="Walnut card tray with white powder coated steel divider and 3 punchout holes."
            className="bg-gray-100 rounded-lg"
          />
          <img
            src="https://images.unsplash.com/photo-1640231912426-0d5feab0b9f9?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=2700&q=80"
            alt="Top down view of walnut card tray with embedded magnets and card groove."
            className="bg-gray-100 rounded-lg"
          />
          <img
            src="https://images.unsplash.com/photo-1591799265444-d66432b91588?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=2360&q=80"
            alt="Side of walnut card tray with card groove and recessed card area."
            className="bg-gray-100 rounded-lg"
          />
          <img
            src="https://images.unsplash.com/photo-1643408875993-d7566153dd89?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=2360&q=80"
            alt="Walnut card tray filled with cards and card angled in dedicated groove."
            className="bg-gray-100 rounded-lg"
          />
        </div>
      </div>
    </div>
  );
}
