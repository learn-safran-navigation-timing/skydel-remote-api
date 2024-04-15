#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the connection parameters to the GPS Receiver from which the simulator will get the simulation start time.
    ///
    /// 
    ///

    class GetGpsTimingReceiver;
    typedef std::shared_ptr<GetGpsTimingReceiver> GetGpsTimingReceiverPtr;
    
    
    class GetGpsTimingReceiver : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsTimingReceiver();

      static GetGpsTimingReceiverPtr create();
      static GetGpsTimingReceiverPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

