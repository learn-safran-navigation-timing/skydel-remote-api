#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Rename data set.
    ///
    /// Name           Type   Description
    /// -------------- ------ ---------------------------------------------
    /// System         string "GPS", "Galileo", "BeiDou", "NavIC" or "QZSS"
    /// DataSetName    string The name of the data set to rename.
    /// NewDataSetName string The new name to be given to the data set.
    ///

    class RenameDataSet;
    typedef std::shared_ptr<RenameDataSet> RenameDataSetPtr;
    
    
    class RenameDataSet : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RenameDataSet();

      RenameDataSet(const std::string& system, const std::string& dataSetName, const std::string& newDataSetName);

      static RenameDataSetPtr create(const std::string& system, const std::string& dataSetName, const std::string& newDataSetName);
      static RenameDataSetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** dataSetName ****
      std::string dataSetName() const;
      void setDataSetName(const std::string& dataSetName);


      // **** newDataSetName ****
      std::string newDataSetName() const;
      void setNewDataSetName(const std::string& newDataSetName);
    };
    
  }
}

