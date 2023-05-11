#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the ID of all spoofer transmitters.
    ///
    /// 
    ///

    class GetAllSpoofTxID;
    typedef std::shared_ptr<GetAllSpoofTxID> GetAllSpoofTxIDPtr;
    
    
    class GetAllSpoofTxID : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllSpoofTxID();

      static GetAllSpoofTxIDPtr create();
      static GetAllSpoofTxIDPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

