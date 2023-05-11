#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIntTxPersistence.
    ///
    /// Name        Type   Description
    /// ----------- ------ ------------------------------------------------------
    /// Persistence bool   True to keep the modifications, false to discard them.
    /// Id          string Transmitter unique identifier.
    ///

    class GetIntTxPersistenceResult;
    typedef std::shared_ptr<GetIntTxPersistenceResult> GetIntTxPersistenceResultPtr;
    
    
    class GetIntTxPersistenceResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxPersistenceResult();

      GetIntTxPersistenceResult(bool persistence, const std::string& id);

      GetIntTxPersistenceResult(CommandBasePtr relatedCommand, bool persistence, const std::string& id);

      static GetIntTxPersistenceResultPtr create(bool persistence, const std::string& id);

      static GetIntTxPersistenceResultPtr create(CommandBasePtr relatedCommand, bool persistence, const std::string& id);
      static GetIntTxPersistenceResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** persistence ****
      bool persistence() const;
      void setPersistence(bool persistence);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIntTxPersistenceResult);
  }
}

