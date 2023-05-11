#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get wether by default transmitters should keep the modification done during simulation.
    ///
    /// 
    ///

    class GetDefaultIntTxPersistence;
    typedef std::shared_ptr<GetDefaultIntTxPersistence> GetDefaultIntTxPersistencePtr;
    
    
    class GetDefaultIntTxPersistence : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetDefaultIntTxPersistence();

      static GetDefaultIntTxPersistencePtr create();
      static GetDefaultIntTxPersistencePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

