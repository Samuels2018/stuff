import React from "react";
import "../styles/timeline.css";
import { FiClock } from "react-icons/fi";
import { BsClockFill, BsFillStarFill } from "react-icons/bs";

export default function Timeline() {
  return (
    <div className="bg-slate-800" id="roadmap">
      <h3 className="block bg-gradient-to-l from-yellow-400 to-green-700 bg-clip-text text-transparent text-5xl font-bold tracking-wide uppercase text-center">
        ROADMAP
      </h3>
      <div className="timeline">
        <div className="timeline__event animated fadeInUp delay-3s timeline__event--type1">
          <div className="timeline__event__icon ">
            <BsClockFill className="text-green-800 h-10 w-10" />
          </div>
          <div className="timeline__event__date">20-03-2022</div>
          <div className="timeline__event__content bg-slate-700">
            <div className="timeline__event__title">Lorem, ipsum dolor.</div>
            <div className="timeline__event__description text-slate-200/70">
              <p>
                Lorem, ipsum dolor sit amet consectetur adipisicing elit. Vel,
                nam! Nam eveniet ut aliquam ab asperiores, accusamus iure veniam
                corporis incidunt reprehenderit accusantium id aut architecto
                harum quidem dolorem in!
              </p>
            </div>
          </div>
        </div>
        <div className="timeline__event animated fadeInUp delay-2s timeline__event--type2">
          <div className="timeline__event__icon">
            <FiClock className="text-green-800 h-10 w-10" />
          </div>
          <div className="timeline__event__date">20-05-2022</div>
          <div className="timeline__event__content bg-slate-700">
            <div className="timeline__event__title">Lunch</div>
            <div className="timeline__event__description text-slate-200/70">
              <p>
                Lorem, ipsum dolor sit amet consectetur adipisicing elit. Vel,
                nam! Nam eveniet ut aliquam ab asperiores, accusamus iure veniam
                corporis incidunt reprehenderit accusantium id aut architecto
                harum quidem dolorem in!
              </p>
            </div>
          </div>
        </div>
        <div className="timeline__event animated fadeInUp delay-1s timeline__event--type3">
          <div className="timeline__event__icon">
            <BsClockFill className="text-green-800 h-10 w-10" />
          </div>
          <div className="timeline__event__date">20-08-2022</div>
          <div className="timeline__event__content bg-slate-700">
            <div className="timeline__event__title">Exercise</div>
            <div className="timeline__event__description text-slate-200/70">
              <p>
                Lorem, ipsum dolor sit amet consectetur adipisicing elit. Vel,
                nam! Nam eveniet ut aliquam ab asperiores, accusamus iure veniam
                corporis incidunt reprehenderit accusantium id aut architecto
                harum quidem dolorem in!
              </p>
            </div>
          </div>
        </div>
        <div className="timeline__event animated fadeInUp timeline__event--type1">
          <div className="timeline__event__icon">
            <BsFillStarFill className="text-green-800 h-10 w-10" />
          </div>
          <div className="timeline__event__date">20-12-2022</div>
          <div className="timeline__event__content bg-slate-700">
            <div className="timeline__event__title">Lorem ipsum dolor sit.</div>
            <div className="timeline__event__description text-slate-200/70">
              <p>
                Lorem, ipsum dolor sit amet consectetur adipisicing elit. Vel,
                nam! Nam eveniet ut aliquam ab asperiores, accusamus iure veniam
                corporis incidunt reprehenderit accusantium id aut architecto
                harum quidem dolorem in!
              </p>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
