#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the ID of all interferences transmitters.
    ///
    /// 
    ///

    class GetAllIntTxID;
    typedef std::shared_ptr<GetAllIntTxID> GetAllIntTxIDPtr;
    
    
    class GetAllIntTxID : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllIntTxID();

      static GetAllIntTxIDPtr create();
      static GetAllIntTxIDPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

