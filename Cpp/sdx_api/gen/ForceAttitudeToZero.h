#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set force vehicle yaw, pitch and roll to zero enabled or disabled
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------
    /// Enabled bool If true, vehicle won't rotate during simulation
    ///

    class ForceAttitudeToZero;
    typedef std::shared_ptr<ForceAttitudeToZero> ForceAttitudeToZeroPtr;
    
    
    class ForceAttitudeToZero : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ForceAttitudeToZero();

      ForceAttitudeToZero(bool enabled);

      static ForceAttitudeToZeroPtr create(bool enabled);
      static ForceAttitudeToZeroPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

