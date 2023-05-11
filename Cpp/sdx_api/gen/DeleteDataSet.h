#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Delete data set.
    ///
    /// Name        Type   Description
    /// ----------- ------ ---------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "NavIC" or "QZSS"
    /// DataSetName string The name of the data set to delete.
    ///

    class DeleteDataSet;
    typedef std::shared_ptr<DeleteDataSet> DeleteDataSetPtr;
    
    
    class DeleteDataSet : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      DeleteDataSet();

      DeleteDataSet(const std::string& system, const std::string& dataSetName);

      static DeleteDataSetPtr create(const std::string& system, const std::string& dataSetName);
      static DeleteDataSetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** dataSetName ****
      std::string dataSetName() const;
      void setDataSetName(const std::string& dataSetName);
    };
    
  }
}

