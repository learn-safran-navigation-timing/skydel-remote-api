#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove all the interference transmitters.
    ///
    /// 
    ///

    class RemoveAllIntTx;
    typedef std::shared_ptr<RemoveAllIntTx> RemoveAllIntTxPtr;
    
    
    class RemoveAllIntTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveAllIntTx();

      static RemoveAllIntTxPtr create();
      static RemoveAllIntTxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

