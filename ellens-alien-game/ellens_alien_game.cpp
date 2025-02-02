namespace targets {
    class Alien
    {
        public:
            int x_coordinate;
            int y_coordinate;

            Alien(int x_coordinate, int y_coordinate)
            {
                this->x_coordinate = x_coordinate;
                this->y_coordinate = y_coordinate;
                health = 3;
            }

            int get_health()
            {
                return health;
            }

            bool hit()
            {
                if (is_alive())
                {
                    health--;
                    return true;
                }

                return false;
            }

            bool is_alive()
            {
                return health > 0;
            }

            bool teleport(int x_coordinate, int y_coordinate)
            {
                this->x_coordinate = x_coordinate;
                this->y_coordinate = y_coordinate;
                return true;
            }

            bool collision_detection(Alien other)
            {
                if (this->x_coordinate == other.x_coordinate && this->y_coordinate == other.y_coordinate) return true;
                return false;
            }

        private:
            int health;

    };
}  // namespace targets