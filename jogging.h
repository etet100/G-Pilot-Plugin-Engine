#ifndef JOGGING_H
#define JOGGING_H

#include <QObject>

/// @class Jogging
/// @brief Provides methods to control jogging operations
///
/// @lua jogging
/// @js jogging
class Jogging : public QObject {
    Q_OBJECT
public:
    Jogging();
    /// @brief Checks if current state allows jogging
    Q_INVOKABLE void jog(int axis, int distance);
    /// @brief Stops any ongoing jogging operation
    Q_INVOKABLE void stop();
    /// @brief Attempts to take control of the jogging system
    /// @param info Optional information about the requester, will be shown as "[info] is jogging"
    /// @return True if control was successfully taken, false otherwise
    Q_INVOKABLE bool take(QString info = "");
    /// @brief Releases control of the jogging system
    Q_INVOKABLE void release();
    /// @brief Self explanatory
    /// @return Current feedrate value (in mm/min)
    Q_INVOKABLE int getFeedrate();
    /// @brief Self explanatory
    /// @return Current step size value (in mm)
    Q_INVOKABLE float getStepSize();
    /// @brief Self explanatory
    Q_INVOKABLE void setFeedrate(int feedrate);
    /// @brief Self explanatory
    Q_INVOKABLE void setStepSize(float step);
    /// @brief Returns list of available feedrates from settings
    Q_INVOKABLE QStringList getFeedrates();
    /// @brief Returns list of available step sizes from settings
    /// @return List of step sizes as strings, -1 represents "continuous"
    Q_INVOKABLE QStringList getStepSizes();
};

#endif // JOGGING_H
