#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether by default transmitters should keep the modification done during simulation.
    ///
    /// Name         Type Description
    /// ------------ ---- --------------------------------------------------------------------------------
    /// DefaultValue bool True if jammers should keep the modifications done during simulation by default.
    ///

    class SetDefaultIntTxPersistence;
    typedef std::shared_ptr<SetDefaultIntTxPersistence> SetDefaultIntTxPersistencePtr;
    
    
    class SetDefaultIntTxPersistence : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetDefaultIntTxPersistence();

      SetDefaultIntTxPersistence(bool defaultValue);

      static SetDefaultIntTxPersistencePtr create(bool defaultValue);
      static SetDefaultIntTxPersistencePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** defaultValue ****
      bool defaultValue() const;
      void setDefaultValue(bool defaultValue);
    };
    
  }
}

