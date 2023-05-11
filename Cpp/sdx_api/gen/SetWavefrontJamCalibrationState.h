#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether the JAM Calibration output is transmitting.
    ///
    /// Name  Type Description
    /// ----- ---- ------------------------------------------------------------------------------
    /// State bool True for the signal to go through the JAM Calibration output, False otherwise.
    ///

    class SetWavefrontJamCalibrationState;
    typedef std::shared_ptr<SetWavefrontJamCalibrationState> SetWavefrontJamCalibrationStatePtr;
    
    
    class SetWavefrontJamCalibrationState : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetWavefrontJamCalibrationState();

      SetWavefrontJamCalibrationState(bool state);

      static SetWavefrontJamCalibrationStatePtr create(bool state);
      static SetWavefrontJamCalibrationStatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** state ****
      bool state() const;
      void setState(bool state);
    };
    
  }
}

