#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Start the simulation at the given PPS count.
    ///
    /// Name Type Description
    /// ---- ---- -------------------------------------------------------------
    /// Msec int  The number of ms after PPS to wait before starting simulation
    ///

    class StartPPS;
    typedef std::shared_ptr<StartPPS> StartPPSPtr;
    
    
    class StartPPS : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      StartPPS();

      StartPPS(int msec);

      static StartPPSPtr create(int msec);
      static StartPPSPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** msec ****
      int msec() const;
      void setMsec(int msec);
    };
    
  }
}

